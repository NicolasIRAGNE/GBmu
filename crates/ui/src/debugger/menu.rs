mod button;

use std::{cell::RefCell, rc::Rc};
use crate::style::Theme;
use bindings::system::Mode;
use button::Button;
use iced::{Element, Length, Row, Space};

pub struct Menu {
    right: Vec<Button>,
    left: Vec<Button>,
    //breakpoints: VecDeque<u16>,
    //status: System,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MenuMsg {
    Frame,
    Run,
    Pause,
    //Tick,
    //Line,
    //Instruction,
    //Second,
    //Breakpoint,
}
impl Menu {
    pub fn new(mode: Rc<RefCell<Mode>>) -> Self {
        let frame = Button::new(MenuMsg::Frame, mode.clone());
        //let second = Button::new(MenuMsg::Second);
        let run = Button::new(MenuMsg::Run, mode.clone());
        let pause =  Button::new(MenuMsg::Pause, mode);

        Self {
            left: vec![],
            right: vec![run, pause, frame],
        }
    }

    pub fn update(&mut self, message: MenuMsg) {
        if let Some(button) = self.left.iter().find(|&button| button.is_button(message)) {
            button.update()
        };
        if let Some(button) = self.right.iter().find(|&button| button.is_button(message)) {
            button.update()
        };
    }

    pub fn view(&mut self, theme: Theme) -> Element<MenuMsg> {
        let right: Element<MenuMsg> = self
            .right
            .iter_mut()
            .fold(Row::new().spacing(10), |row, button| {
                let element: Element<MenuMsg> = button.view(theme);
                row.push(element)
            })
            .into();

        let left: Element<MenuMsg> = self
            .left
            .iter_mut()
            .fold(Row::new().spacing(10), |row, button| {
                let element: Element<MenuMsg> = button.view(theme);
                row.push(element)
            })
            .into();
        let space = Space::with_width(Length::Fill);
        Row::new()
            .push(left)
            .push(space)
            .push(right)
            .padding(5)
            .into()
    }
}
