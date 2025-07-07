use anyhow::Error;

pub trait Currency
where
    Self: Eq + PartialEq + Ord + PartialOrd + Sized,
{
    fn get_whole(&self) -> u32;
    fn set_whole(&mut self, new_value: u32);
    fn get_fractional(&self) -> u32;
    fn set_fractional(&mut self, new_value: u32);
    fn get_currency_name() -> String;

    fn add(&mut self, currency: Self) -> anyhow::Result<()> {
        self.set_fractional(self.get_fractional() + currency.get_fractional());
        if self.get_fractional() > 100 {
            self.set_fractional(self.get_fractional() - 100);
            self.set_whole(self.get_whole() + 1);
        }
        self.set_whole(self.get_whole() + currency.get_whole());
        Ok(())
    }

    fn sub(&mut self, currency: Self) -> anyhow::Result<()> {
        if *self < currency {
            return Err(Error::msg(
                "Invalid Subtractions: Cannot be Negative Currency",
            ));
        }
        if self.get_fractional() < currency.get_fractional() {
            self.set_fractional(self.get_fractional() + 100);
            self.set_whole(self.get_whole() - 1);
        }
        self.set_fractional(self.get_fractional() - currency.get_fractional());
        self.set_whole(self.get_whole() - currency.get_whole());
        Ok(())
    }

    fn print(&self) {
        println!(
            "{}.{:0>2} {}",
            self.get_whole(),
            self.get_fractional(),
            Self::get_currency_name()
        )
    }
}
