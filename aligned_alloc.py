def aligned_alloc(bytes):
    MINSIZE = 16
    overflow = bytes % MINSIZE
    if overflow != 0:
        bytes += (MINSIZE - overflow)
    return bytes