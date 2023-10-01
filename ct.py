import ctypes

# 라이브러리 로드
example_strings = ctypes.CDLL('./libcsmith.so')

# 함수 프로토타입 정의
example_strings.gen_csmith.argtypes = (ctypes.c_int, ctypes.POINTER(ctypes.c_char_p))

def call_print_string_array(str_list):
    c_string_array = (ctypes.c_char_p * len(str_list))()
    for i, string in enumerate(str_list):
        c_string_array[i] = bytes(string, 'utf-8')
    return example_strings.gen_csmith(len(str_list), c_string_array)

# 테스트
if __name__ == "__main__":
    test_strings = ["csmith", "--max-array-dim","3", "-o", "csmith.c"]
    ret = call_print_string_array(test_strings)
    print(ret)