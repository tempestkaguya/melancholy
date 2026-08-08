use discord_rich_presence::{activity, DiscordIpc, DiscordIpcClient};

/*
Beginning Melancholy

status: "no file opened yet"
details: "Reverse engineering with Melancholy!"
*/

pub async fn activity(state: &str, details: &str) -> Result<(), Box<dyn std::error::Error>> {
    let mut client = DiscordIpcClient::new("1529606923530277017");
    
    client.connect()?; 
    let payload = activity::Activity::new()
        .state(state)
        .details(details)
        .assets(activity::Assets::new()
            .large_image("test")
            .large_text("Melancholy")
    );
        
    client.set_activity(payload)?;
    loop {
        tokio::time::sleep(std::time::Duration::from_secs(10)).await;
    }
}