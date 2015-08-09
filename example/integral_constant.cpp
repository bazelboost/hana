/*
@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/assert.hpp>
#include <boost/hana/config.hpp>
#include <boost/hana/integral_constant.hpp>
#include <boost/hana/tuple.hpp>

#include <string>
#include <vector>
namespace hana = boost::hana;


int main() {

{

//! [operators]
BOOST_HANA_CONSTANT_CHECK(hana::int_<1> + hana::int_<3> == hana::int_<4>);

// Mixed-type operations are supported, but only when it involves a
// promotion, and not a conversion that could be lossy.
BOOST_HANA_CONSTANT_CHECK(hana::size_t<3> * hana::ushort<5> == hana::size_t<15>);
BOOST_HANA_CONSTANT_CHECK(hana::llong<15> == hana::int_<15>);
//! [operators]

}{

//! [times_loop_unrolling]
std::string s;
for (char c = 'x'; c <= 'z'; ++c)
    hana::int_<5>.times([&] { s += c; });

BOOST_HANA_RUNTIME_CHECK(s == "xxxxxyyyyyzzzzz");
//! [times_loop_unrolling]

}{

//! [as_static_member]
std::string s;
for (char c = 'x'; c <= 'z'; ++c)
    decltype(hana::int_<5>)::times([&] { s += c; });

BOOST_HANA_RUNTIME_CHECK(s == "xxxxxyyyyyzzzzz");
//! [as_static_member]

}{

//! [times_higher_order]
std::string s;
BOOST_HANA_CONSTEXPR_LAMBDA auto functions = hana::make_tuple(
    [&] { s += "x"; },
    [&] { s += "y"; },
    [&] { s += "z"; }
);
hana::for_each(functions, hana::int_<5>.times);
BOOST_HANA_RUNTIME_CHECK(s == "xxxxxyyyyyzzzzz");
//! [times_higher_order]

}{

//! [times_with_index_runtime]
std::vector<int> v;
hana::int_<5>.times.with_index([&](auto index) { v.push_back(index); });

BOOST_HANA_RUNTIME_CHECK(v == std::vector<int>{0, 1, 2, 3, 4});
//! [times_with_index_runtime]

//! [times_with_index_compile_time]
constexpr auto xs = hana::tuple_c<int, 0, 1, 2>;
hana::int_<3>.times.with_index([xs](auto index) {
    BOOST_HANA_CONSTANT_CHECK(xs[index] == index);
});
//! [times_with_index_compile_time]

}{

//! [literals]
using namespace hana::literals; // contains the _c suffix

BOOST_HANA_CONSTANT_CHECK(1234_c == hana::llong<1234>);
BOOST_HANA_CONSTANT_CHECK(-1234_c == hana::llong<-1234>);
BOOST_HANA_CONSTANT_CHECK(1_c + (3_c * 4_c) == hana::llong<1 + (3 * 4)>);
//! [literals]

}{

//! [integral_constant]
BOOST_HANA_CONSTANT_CHECK(hana::integral_constant<int, 2> == hana::int_<2>);
static_assert(decltype(hana::integral_constant<int, 2>)::value == 2, "");
//! [integral_constant]

}

}
