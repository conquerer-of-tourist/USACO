use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let mut n: i64 = input.trim().parse().unwrap();

    while n != 1 {
        print!("{} ", n);

        if n % 2 == 0 {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
    }

    println!("1");
}