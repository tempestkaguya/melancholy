use shared_memory::{Shmem, ShmemConf, ShmemError};

pub unsafe fn create_smipc<T: Sized>(
    os_id: &str,
    size: usize,
) -> Result<(&'static mut T, Shmem), ShmemError> {
    let shm = ShmemConf::new().size(size).os_id(os_id).create()?;

    Ok((unsafe { &mut *(shm.as_ptr() as *mut T) }, shm))
}
