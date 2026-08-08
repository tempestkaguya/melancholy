use thiserror::Error;

#[derive(Debug, Error)]
pub enum Errors {
    #[error("failed to connect in the discord activity")]
    FailConnection
}