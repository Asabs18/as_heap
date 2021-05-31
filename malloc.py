def malloc(bytes):
    if bytes <= 0:
        raise ValueError('Value too small to allocate!')
    return bytes