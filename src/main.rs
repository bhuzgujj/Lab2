use crate::{currency::Currency, drachma::Drachma, peso::Peso};

mod currency;
mod drachma;
mod peso;

fn main() {
    let mut dra = Drachma {
        whole: 5,
        fractional: 5,
    };
    let _ = dra.sub(Drachma {
        whole: 3,
        fractional: 12,
    });
    dra.print();
    let mut peso = Peso {
        whole: 9,
        fractional: 2,
    };
    let _ = peso.add(Peso {
        whole: 3,
        fractional: 1,
    });
    peso.print();
}
