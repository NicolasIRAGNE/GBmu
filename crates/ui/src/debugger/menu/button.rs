use std::{cell::RefCell, sync::Arc};

use crate::style::Theme;
use bindings::system::Mode;
use iced::{button, Element};

use super::MenuMsg;
use crate::widgets::Text;

pub struct Button {
    message: MenuMsg,
    state: button::State,
    mode: Arc<RefCell<Mode>>,
}

impl Button {
    pub fn new(message: MenuMsg, mode: Arc<RefCell<Mode>>) -> Self {
        let state = button::State::default();
        Self {
            state,
            message,
            mode,
        }
    }

    pub fn update(&self) {
        match self.message {
            MenuMsg::Instruction => {
                *self.mode.borrow_mut() = Mode::Instruction;
            }
            MenuMsg::Frame => {
                *self.mode.borrow_mut() = Mode::Frame;
            }
            MenuMsg::Run => {
                *self.mode.borrow_mut() = Mode::Run;
            }
            MenuMsg::Pause => {
                *self.mode.borrow_mut() = Mode::Pause;
            }
        }
    }

    pub fn is_button(&self, message: MenuMsg) -> bool {
        self.message == message
    }

    pub fn view(&mut self, _theme: Theme) -> Element<MenuMsg> {
        let text = format!("{:?}", self.message);
        let text = format!("{:^10}", text);
        let text = Text::new(&text).medium(20);
        button::Button::new(&mut self.state, text)
            .on_press(self.message)
            .into()
    }
}
