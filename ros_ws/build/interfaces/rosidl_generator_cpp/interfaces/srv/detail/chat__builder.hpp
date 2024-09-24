// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:srv/Chat.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__CHAT__BUILDER_HPP_
#define INTERFACES__SRV__DETAIL__CHAT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/srv/detail/chat__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_Chat_Request_message
{
public:
  Init_Chat_Request_message()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::Chat_Request message(::interfaces::srv::Chat_Request::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::Chat_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::Chat_Request>()
{
  return interfaces::srv::builder::Init_Chat_Request_message();
}

}  // namespace interfaces


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_Chat_Response_response
{
public:
  Init_Chat_Response_response()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::Chat_Response response(::interfaces::srv::Chat_Response::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::Chat_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::Chat_Response>()
{
  return interfaces::srv::builder::Init_Chat_Response_response();
}

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__CHAT__BUILDER_HPP_
