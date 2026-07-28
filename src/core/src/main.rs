use discord_rich_presence::{activity, DiscordIpc, DiscordIpcClient};
use goblin::{error, Object};
use std::fs;

#[cxx::bridge]
mod ffi {
    extern "Rust" {
        fn parse(path: &String) -> Result<()>;
    }
}

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

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let mut client = DiscordIpcClient::new("1529606923530277017");
    
    client.connect()?; 
    let payload = activity::Activity::new()
        .state("no file opened yet")
        .details("Reverse engineering with Melancholy!")
        .assets(activity::Assets::new()
            .large_image("test")
            .large_text("epic")
    );
        
    client.set_activity(payload)?;
    loop {
        std::thread::sleep(std::time::Duration::from_secs(10));
    }
}