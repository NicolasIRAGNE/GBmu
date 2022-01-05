use crate::bindings;

#[repr(C)]
pub struct Registers {
    pub f: cty::c_uchar,
    pub a: cty::c_uchar,
    pub c: cty::c_uchar,
    pub b: cty::c_uchar,
    pub e: cty::c_uchar,
    pub d: cty::c_uchar,
    pub l: cty::c_uchar,
    pub h: cty::c_uchar,
    pub sp: cty::c_uint,
    pub pc: cty::c_uint,
}

pub fn test_link() {
    unsafe { bindings::test_link();};
}
