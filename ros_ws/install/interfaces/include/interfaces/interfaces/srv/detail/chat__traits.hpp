// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:srv/Chat.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__CHAT__TRAITS_HPP_
#define INTERFACES__SRV__DETAIL__CHAT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interfaces/srv/detail/chat__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Chat_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Chat_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Chat_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::srv::Chat_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::srv::Chat_Request & msg)
{
  return interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::srv::Chat_Request>()
{
  return "interfaces::srv::Chat_Request";
}

template<>
inline const char * name<interfaces::srv::Chat_Request>()
{
  return "interfaces/srv/Chat_Request";
}

template<>
struct has_fixed_size<interfaces::srv::Chat_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<interfaces::srv::Chat_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<interfaces::srv::Chat_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Chat_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: response
  {
    out << "response: ";
    rosidl_generator_traits::value_to_yaml(msg.response, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Chat_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "response: ";
    rosidl_generator_traits::value_to_yaml(msg.response, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Chat_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::srv::Chat_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::srv::Chat_Response & msg)
{
  return interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::srv::Chat_Response>()
{
  return "interfaces::srv::Chat_Response";
}

template<>
inline const char * name<interfaces::srv::Chat_Response>()
{
  return "interfaces/srv/Chat_Response";
}

template<>
struct has_fixed_size<interfaces::srv::Chat_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<interfaces::srv::Chat_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<interfaces::srv::Chat_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::srv::Chat>()
{
  return "interfaces::srv::Chat";
}

template<>
inline const char * name<interfaces::srv::Chat>()
{
  return "interfaces/srv/Chat";
}

template<>
struct has_fixed_size<interfaces::srv::Chat>
  : std::integral_constant<
    bool,
    has_fixed_size<interfaces::srv::Chat_Request>::value &&
    has_fixed_size<interfaces::srv::Chat_Response>::value
  >
{
};

template<>
struct has_bounded_size<interfaces::srv::Chat>
  : std::integral_constant<
    bool,
    has_bounded_size<interfaces::srv::Chat_Request>::value &&
    has_bounded_size<interfaces::srv::Chat_Response>::value
  >
{
};

template<>
struct is_service<interfaces::srv::Chat>
  : std::true_type
{
};

template<>
struct is_service_request<interfaces::srv::Chat_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interfaces::srv::Chat_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__SRV__DETAIL__CHAT__TRAITS_HPP_
