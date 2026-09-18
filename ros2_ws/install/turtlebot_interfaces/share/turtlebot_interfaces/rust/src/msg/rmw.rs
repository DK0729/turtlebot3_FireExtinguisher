#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "turtlebot_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__turtlebot_interfaces__msg__Yolo() -> *const std::ffi::c_void;
}

#[link(name = "turtlebot_interfaces__rosidl_generator_c")]
extern "C" {
    fn turtlebot_interfaces__msg__Yolo__init(msg: *mut Yolo) -> bool;
    fn turtlebot_interfaces__msg__Yolo__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Yolo>, size: usize) -> bool;
    fn turtlebot_interfaces__msg__Yolo__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Yolo>);
    fn turtlebot_interfaces__msg__Yolo__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Yolo>, out_seq: *mut rosidl_runtime_rs::Sequence<Yolo>) -> bool;
}

// Corresponds to turtlebot_interfaces__msg__Yolo
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Yolo {

    // This member is not documented.
    #[allow(missing_docs)]
    pub x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: f64,

}



impl Default for Yolo {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !turtlebot_interfaces__msg__Yolo__init(&mut msg as *mut _) {
        panic!("Call to turtlebot_interfaces__msg__Yolo__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Yolo {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtlebot_interfaces__msg__Yolo__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtlebot_interfaces__msg__Yolo__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtlebot_interfaces__msg__Yolo__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Yolo {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Yolo where Self: Sized {
  const TYPE_NAME: &'static str = "turtlebot_interfaces/msg/Yolo";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__turtlebot_interfaces__msg__Yolo() }
  }
}


