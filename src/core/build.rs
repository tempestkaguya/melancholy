use std::env;
use std::path::PathBuf;

fn main() {
    let manifest_dir = env::var("CARGO_MANIFEST_DIR").unwrap();
    let mut dir = PathBuf::from(manifest_dir);
    dir.pop();
    dir.pop();

    cxx_build::bridge("src/main.rs")
        .include(&dir)
        .compile("melancholy");
}