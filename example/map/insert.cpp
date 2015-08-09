/*
@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/assert.hpp>
#include <boost/hana/insert.hpp>
#include <boost/hana/map.hpp>
#include <boost/hana/pair.hpp>
#include <boost/hana/type.hpp>

#include <string>
namespace hana = boost::hana;
using namespace std::literals;


int main() {
    auto m = hana::make_map(
        hana::make_pair(hana::type<int>, "abcd"s),
        hana::make_pair(hana::type<void>, 1234)
    );

    BOOST_HANA_RUNTIME_CHECK(
        hana::insert(m, hana::make_pair(hana::type<float>, 'x')) ==
        hana::make_map(
            hana::make_pair(hana::type<int>, "abcd"s),
            hana::make_pair(hana::type<void>, 1234),
            hana::make_pair(hana::type<float>, 'x')
        )
    );

    BOOST_HANA_RUNTIME_CHECK(hana::insert(m, hana::make_pair(hana::type<void>, 'x')) == m);
}
