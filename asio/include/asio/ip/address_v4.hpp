//
// ip/address_v4.hpp
// ~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef ASIO_IP_ADDRESS_V4_HPP
#define ASIO_IP_ADDRESS_V4_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "asio/detail/push_options.hpp"

#include "asio/detail/config.hpp"

#include "asio/detail/push_options.hpp"
#if !defined(BOOST_NO_IOSTREAM)
# include <iosfwd>
#endif // !defined(BOOST_NO_IOSTREAM)
#include <string>
#include <boost/array.hpp>
#include "asio/detail/pop_options.hpp"

#include "asio/error_code.hpp"
#include "asio/detail/socket_types.hpp"

namespace asio {
namespace ip {

/// Implements IP version 4 style addresses.
/**
 * The asio::ip::address_v4 class provides the ability to use and
 * manipulate IP version 4 addresses.
 *
 * @par Thread Safety
 * @e Distinct @e objects: Safe.@n
 * @e Shared @e objects: Unsafe.
 */
class address_v4
{
public:
  /// The type used to represent an address as an array of bytes.
  typedef boost::array<unsigned char, 4> bytes_type;

  /// Default constructor.
  address_v4();

  /// Construct an address from raw bytes.
  ASIO_DECL explicit address_v4(const bytes_type& bytes);

  /// Construct an address from a unsigned long in host byte order.
  ASIO_DECL explicit address_v4(unsigned long addr);

  /// Copy constructor.
  address_v4(const address_v4& other);

  /// Assign from another address.
  address_v4& operator=(const address_v4& other);

  /// Get the address in bytes, in network byte order.
  ASIO_DECL bytes_type to_bytes() const;

  /// Get the address as an unsigned long in host byte order
  ASIO_DECL unsigned long to_ulong() const;

  /// Get the address as a string in dotted decimal format.
  ASIO_DECL std::string to_string() const;

  /// Get the address as a string in dotted decimal format.
  ASIO_DECL std::string to_string(asio::error_code& ec) const;

  /// Create an address from an IP address string in dotted decimal form.
  ASIO_DECL static address_v4 from_string(const char* str);

  /// Create an address from an IP address string in dotted decimal form.
  ASIO_DECL static address_v4 from_string(
      const char* str, asio::error_code& ec);

  /// Create an address from an IP address string in dotted decimal form.
  ASIO_DECL static address_v4 from_string(const std::string& str);

  /// Create an address from an IP address string in dotted decimal form.
  ASIO_DECL static address_v4 from_string(
      const std::string& str, asio::error_code& ec);

  /// Determine whether the address is a class A address.
  ASIO_DECL bool is_class_a() const;

  /// Determine whether the address is a class B address.
  ASIO_DECL bool is_class_b() const;

  /// Determine whether the address is a class C address.
  ASIO_DECL bool is_class_c() const;

  /// Determine whether the address is a multicast address.
  ASIO_DECL bool is_multicast() const;

  /// Compare two addresses for equality.
  friend bool operator==(const address_v4& a1, const address_v4& a2);

  /// Compare two addresses for inequality.
  friend bool operator!=(const address_v4& a1, const address_v4& a2);

  /// Compare addresses for ordering.
  friend bool operator<(const address_v4& a1, const address_v4& a2);

  /// Compare addresses for ordering.
  friend bool operator>(const address_v4& a1, const address_v4& a2);

  /// Compare addresses for ordering.
  friend bool operator<=(const address_v4& a1, const address_v4& a2);

  /// Compare addresses for ordering.
  friend bool operator>=(const address_v4& a1, const address_v4& a2);

  /// Obtain an address object that represents any address.
  static address_v4 any();

  /// Obtain an address object that represents the loopback address.
  static address_v4 loopback();

  /// Obtain an address object that represents the broadcast address.
  static address_v4 broadcast();

  /// Obtain an address object that represents the broadcast address that
  /// corresponds to the specified address and netmask.
  ASIO_DECL static address_v4 broadcast(
      const address_v4& addr, const address_v4& mask);

  /// Obtain the netmask that corresponds to the address, based on its address
  /// class.
  ASIO_DECL static address_v4 netmask(const address_v4& addr);

private:
  // The underlying IPv4 address.
  asio::detail::in4_addr_type addr_;
};

#if !defined(BOOST_NO_IOSTREAM)

/// Output an address as a string.
/**
 * Used to output a human-readable string for a specified address.
 *
 * @param os The output stream to which the string will be written.
 *
 * @param addr The address to be written.
 *
 * @return The output stream.
 *
 * @relates asio::ip::address_v4
 */
template <typename Elem, typename Traits>
std::basic_ostream<Elem, Traits>& operator<<(
    std::basic_ostream<Elem, Traits>& os, const address_v4& addr);

#endif // !defined(BOOST_NO_IOSTREAM)

} // namespace ip
} // namespace asio

#include "asio/detail/pop_options.hpp"

#include "asio/ip/impl/address_v4.hpp"
#if defined(ASIO_HEADER_ONLY)
# include "asio/ip/impl/address_v4.ipp"
#endif // defined(ASIO_HEADER_ONLY)

#endif // ASIO_IP_ADDRESS_V4_HPP
