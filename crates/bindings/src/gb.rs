#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]


#[repr(C)]
pub struct CoolStruct {
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
