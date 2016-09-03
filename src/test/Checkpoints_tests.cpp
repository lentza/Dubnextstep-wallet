//
// Unit tests for block-chain checkpoints
//
#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/test/unit_test.hpp>
#include <boost/foreach.hpp>

#include "../checkpoints.h"
#include "../util.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(Checkpoints_tests)

BOOST_AUTO_TEST_CASE(sanity)
{
    uint256 p11111 = uint256("0000079f611b58f8fcc72ee6f45606c999c593179528400f9a766c46b883f1fc");
    uint256 p134444 = uint256("0x0000000000000789bffd4cd315cd34ffd4a594f430ac814c91184a0d42d2b0fe");
    BOOST_CHECK(Checkpoints::CheckBlock(11111, p11111));
    BOOST_CHECK(Checkpoints::CheckBlock(134444, p134444));

    
    // Wrong hashes at checkpoints should fail:
    BOOST_CHECK(!Checkpoints::CheckBlock(11111, p134444));
    BOOST_CHECK(!Checkpoints::CheckBlock(134444, p11111));

    // ... but any hash not at a checkpoint should succeed:
    BOOST_CHECK(Checkpoints::CheckBlock(11111+1, p134444));
    BOOST_CHECK(Checkpoints::CheckBlock(134444+1, p11111));

    BOOST_CHECK(Checkpoints::GetTotalBlocksEstimate() >= 134444);
}    

BOOST_AUTO_TEST_SUITE_END()
