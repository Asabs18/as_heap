def realloc(bytes, newBytes):
    if newBytes <= 0:
        raise ValueError('Value too small to allocate!')
    return newBytes