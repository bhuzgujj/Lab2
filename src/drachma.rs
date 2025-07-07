use crate::currency::Currency;

#[derive(Eq, PartialEq, PartialOrd, Ord)]
pub struct Drachma {
    pub whole: u32,
    pub fractional: u32,
}

impl Currency for Drachma {
    fn get_whole(&self) -> u32 {
        self.whole
    }

    fn set_whole(&mut self, new_value: u32) {
        self.whole = new_value;
    }

    fn get_fractional(&self) -> u32 {
        self.fractional
    }

    fn set_fractional(&mut self, new_value: u32) {
        self.fractional = new_value;
    }

    fn get_currency_name() -> String {
        "Drachma".to_string()
    }
}
