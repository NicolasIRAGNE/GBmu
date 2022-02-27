use crate::style::Theme;
use iced::{button, Element};

use super::MenuMsg;
use crate::widgets::Text;

pub struct Button {
    message: MenuMsg,
    state: button::State,
}

impl Button {
    pub fn new(message: MenuMsg) -> Self {
        let state = button::State::default();
        Self {
            state,
            message,
        }
    }

    pub fn update(&self) {
        //match self.message {
            // MenuMsg::Tick => {
            //     status.mode(Mode::Tick);
            // }
            // MenuMsg::Line => {
            //     status.mode(Mode::Line);
            // }
            // MenuMsg::Frame => {
            //     println!("Mode Frame pressed");
            //     status.mode(Mode::Frame);
            // }
            // MenuMsg::Instruction => {
            //     status.mode(Mode::Instruction);
            // }
            // MenuMsg::Second => {
            //     status.second();
            // }
            // MenuMsg::Run => {
            //     status.run();
            // }
            // MenuMsg::Breakpoint => {}
        //}
    }

    pub fn is_button(&self, message: MenuMsg) -> bool {
        self.message == message
    }

    pub fn view(&'static mut self, theme: Theme) -> Element<MenuMsg> {
        let text = format!("{:?}", self.message);
        let text = format!("{:^10}", text);
        let text = Text::new(&text).medium(20);
        button::Button::new(&mut self.state, text)
            .on_press(self.message)
            .style(theme)
            .into()
    }
}
