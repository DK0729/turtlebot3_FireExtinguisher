#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to turtlebot_interfaces__srv__Extinguish_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Extinguish_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub y_val: f32,

}



impl Default for Extinguish_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Extinguish_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Extinguish_Request {
  type RmwMsg = super::srv::rmw::Extinguish_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        y_val: msg.y_val,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      y_val: msg.y_val,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      y_val: msg.y_val,
    }
  }
}


// Corresponds to turtlebot_interfaces__srv__Extinguish_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Extinguish_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: i32,

}



impl Default for Extinguish_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Extinguish_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Extinguish_Response {
  type RmwMsg = super::srv::rmw::Extinguish_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
    }
  }
}






#[link(name = "turtlebot_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__turtlebot_interfaces__srv__Extinguish() -> *const std::ffi::c_void;
}

// Corresponds to turtlebot_interfaces__srv__Extinguish
#[allow(missing_docs, non_camel_case_types)]
pub struct Extinguish;

impl rosidl_runtime_rs::Service for Extinguish {
    type Request = Extinguish_Request;
    type Response = Extinguish_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__turtlebot_interfaces__srv__Extinguish() }
    }
}


