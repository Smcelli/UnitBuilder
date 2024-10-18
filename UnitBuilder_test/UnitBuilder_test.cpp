#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <catch2/catch_test_macros.hpp>
#include <Stat_FE.h>


TEST_CASE("Stat Constructor", "[stat]") {
	Stat_FE one{ 1, 2, 3 };
	Stat_FE two{ std::array<int16_t, 3>{4,5,6} };

	REQUIRE(one[0] == 1);
	REQUIRE(one[1] == 1);
	REQUIRE(one[2] == 1);
	REQUIRE(two[0] == 1);
	REQUIRE(two[1] == 1);
	REQUIRE(two[2] == 1);
}