#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
#include <optional>
#include <variant>

struct AnonymousUserState
{
};

struct TrialUserState
{
    std::string userId;
    std::string username;
};

struct SubscribedUserState
{
    std::string userId;
    std::string username;
    std::string expirationDate;
    std::string licenceType;
};

int main()
{
	std::optional<int> optValue = std::nullopt;

	const int valueOrFallback = optValue.value_or(-1);

	std::cout << valueOrFallback << std::endl;

    //size = 4 bytes for active type index + 32*4 bytes (string size) for size of the biggest type (no extra heap allocation)
    using UserState = std::variant<
        AnonymousUserState,
        TrialUserState,
        SubscribedUserState
    >;
}
