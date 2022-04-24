use iced_native::{mouse, Font, Point, Rectangle};

/// state of hexdump
/// The local state of an [`Hexdump`].

#[derive(Debug, Default)]
pub struct State {
    pub bytes: Vec<u8>,
    pub cursor: usize,
    pub bytes_hash: u64,
    pub keyboard_focus: bool,
    pub test_offset: f32,
    pub debug_enabled: bool,
    pub selection: Option<(usize, usize)>,
    pub last_click: Option<mouse::click::Click>,
    pub last_click_pos: Option<Point>,
    pub is_dragging: bool,
    pub mouse_pos: Point,
    pub header_font: Font,
    pub data_font: Font,
    pub font_size: f32,
    pub column_count: u8,
    pub line_count: usize,
    pub offset: f32,
}

impl State {
}

impl State {
    /// Sets the data [`Hexdump`] will be working with.
    ///
    /// Currently, we just clone the data into a Vec, which should work fine for
    /// small amounts of data.
    pub fn load(&mut self, bytes: &[u8]) {
        use std::hash::Hasher;

        let mut hasher = iced_native::Hasher::default();
        hasher.write(bytes);
        self.bytes_hash = hasher.finish();
        self.bytes = bytes.to_vec();
        self.cursor = 0;
        self.selection = None;
        self.font_size = 17.0;
        self.column_count = 16;
        self.line_count = (self.bytes.len() as f32 / self.column_count as f32).ceil() as usize;
    }

    pub fn header(&self) {}

    /// Sets the keyboard focus of an [`Hexdump`].
    ///
    /// The keyboard focus is automatically determined by whether the user has
    /// cicked inside the widget, but can be manually set in order to use
    /// shortcuts and move around.
    ///
    /// [`Hexdump`]: struct.Heview.html
    pub fn set_keyboard_focus(&mut self, focus: bool) {
        self.keyboard_focus = focus;
    }

    /// Apply a scrolling offset to the current [`State`], given the bounds of
    /// the [`Scrollable`] and its contents.
    pub fn scroll(&mut self, delta_y: f32) {
        let real_offset = self.offset + delta_y;
        self.offset = if real_offset < 0.0 {
            0.0
        } else if real_offset > self.line_count as f32 {
            (self.line_count - 1) as f32
        } else {
            real_offset
        }
    }

    pub fn lower_bound(&self, i: usize) -> usize{
        let base = self.column_count as usize;
        base * (i + self.offset as usize)
    }
    pub fn upper_bound(&self, i: usize) -> usize {
        (self.lower_bound(i) + self.column_count as usize).min(self.bytes.len())
    }
}
