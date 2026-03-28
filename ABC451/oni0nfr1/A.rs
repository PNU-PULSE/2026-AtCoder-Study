use std::{
    io::{self, Read},
    str::{FromStr, SplitWhitespace},
};

fn read_value<T>(tokens: &mut SplitWhitespace<'_>) -> Option<T>
where
    T: FromStr,
    T::Err: std::fmt::Debug,
{
    tokens.next()?.parse::<T>().ok()
}

fn main() {
    let mut input_buf = String::new();
    io::stdin().read_to_string(&mut input_buf).unwrap();
    let mut input = input_buf.split_whitespace();

    let s: String = read_value(&mut input).unwrap();

    if s.len() % 5 == 0 {
        print!("Yes");
    } else {
        print!("No");
    }
}
