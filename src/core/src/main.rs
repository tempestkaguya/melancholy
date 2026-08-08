pub mod components;
pub mod status;

use discord_rich_presence::{activity, DiscordIpc, DiscordIpcClient};
use goblin::{error, Object};
use std::fs;

use status::Errors;
use components::discord_activity::activity;

fn parse(path: &String) -> error::Result<()> {
    let buffer = fs::read(path)?;
    match Object::parse(&buffer) {
        Ok(Object::Elf(elf)) => {
            println!("{:#?}", elf);
        }
        _ => {}
    }
    Ok(())
}

#[tokio::main]
async fn main() {
    if let Err(_) = activity("no file opened yet", "Reverse engineering with Melancholy!").await {
        Errors::FailConnection;
    };

    
}