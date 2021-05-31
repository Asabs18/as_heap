def aligned_alloc(bytes):
    MINSIZE = 16
    if bytes < 16:
        raise ValueError('Value too small to allocate!')
    overflow = bytes % MINSIZE
    if overflow != 0:
        bytes += (MINSIZE - overflow)
    return bytes