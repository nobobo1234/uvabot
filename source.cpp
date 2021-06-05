#include "sleepy_discord/sleepy_discord.h"
#include <fstream>
#include <string>

std::ifstream tokenFile;

class MyClientClass : public SleepyDiscord::DiscordClient {
public:
	using SleepyDiscord::DiscordClient::DiscordClient;
	void onMessage(SleepyDiscord::Message message) override {
		if (message.startsWith("whcg hello"))
			sendMessage(message.channelID, "Hello " + message.author.username);
	}
};

int main() {
	tokenFile.open("./token.txt");

	std::string token;
	std::getline(tokenFile, token);

	MyClientClass client(token, SleepyDiscord::USER_CONTROLED_THREADS);

	tokenFile.close();
	client.run();
}