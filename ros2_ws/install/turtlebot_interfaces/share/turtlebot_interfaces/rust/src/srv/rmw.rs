#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "turtlebot_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__turtlebot_interfaces__srv__Extinguish_Request() -> *const std::ffi::c_void;
}

#[link(name = "turtlebot_interfaces__rosidl_generator_c")]
extern "C" {
    fn turtlebot_interfaces__srv__Extinguish_Request__init(msg: *mut Extinguish_Request) -> bool;
    fn turtlebot_interfaces__srv__Extinguish_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Extinguish_Request>, size: usize) -> bool;
    fn turtlebot_interfaces__srv__Extinguish_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Extinguish_Request>);
    fn turtlebot_interfaces__srv__Extinguish_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Extinguish_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Extinguish_Request>) -> bool;
}

// Corresponds to turtlebot_interfaces__srv__Extinguish_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Extinguish_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub y_val: f32,

}



impl Default for Extinguish_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !turtlebot_interfaces__srv__Extinguish_Request__init(&mut msg as *mut _) {
        panic!("Call to turtlebot_interfaces__srv__Extinguish_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Extinguish_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtlebot_interfaces__srv__Extinguish_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtlebot_interfaces__srv__Extinguish_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtlebot_interfaces__srv__Extinguish_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Extinguish_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Extinguish_Request where Self: Sized {
  const TYPE_NAME: &'static str = "turtlebot_interfaces/srv/Extinguish_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__turtlebot_interfaces__srv__Extinguish_Request() }
  }
}


#[link(name = "turtlebot_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__turtlebot_interfaces__srv__Extinguish_Response() -> *const std::ffi::c_void;
}

#[link(name = "turtlebot_interfaces__rosidl_generator_c")]
extern "C" {
    fn turtlebot_interfaces__srv__Extinguish_Response__init(msg: *mut Extinguish_Response) -> bool;
    fn turtlebot_interfaces__srv__Extinguish_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Extinguish_Response>, size: usize) -> bool;
    fn turtlebot_interfaces__srv__Extinguish_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Extinguish_Response>);
    fn turtlebot_interfaces__srv__Extinguish_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Extinguish_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Extinguish_Response>) -> bool;
}

// Corresponds to turtlebot_interfaces__srv__Extinguish_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Extinguish_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: i32,

}



impl Default for Extinguish_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !turtlebot_interfaces__srv__Extinguish_Response__init(&mut msg as *mut _) {
        panic!("Call to turtlebot_interfaces__srv__Extinguish_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Extinguish_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtlebot_interfaces__srv__Extinguish_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtlebot_interfaces__srv__Extinguish_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtlebot_interfaces__srv__Extinguish_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Extinguish_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Extinguish_Response where Self: Sized {
  const TYPE_NAME: &'static str = "turtlebot_interfaces/srv/Extinguish_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__turtlebot_interfaces__srv__Extinguish_Response() }
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


