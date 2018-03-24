const char* quantize_func = 
"static inline int quantize(float val, unsigned fid) {\n"
"  const float* array = &threshold[th_begin[fid]];\n"
"  int len = th_len[fid];\n"
"  int low = 0;\n"
"  int high = len;\n"
"  int mid;\n"
"  float mval;\n"
"  if (val < array[0]) {\n"
"    return -10;\n"
"  }\n"
"  while (low + 1 < high) {\n"
"    mid = (low + high) / 2;\n"
"    mval = array[mid];\n"
"    if (val == mval) {\n"
"      return mid * 2;\n"
"    } else if (val < mval) {\n"
"      high = mid;\n"
"    } else {\n"
"      low = mid;\n"
"    }\n"
"  }\n"
"  if (array[low] == val) {\n"
"    return low * 2;\n"
"  } else if (high == len) {\n"
"    return len * 2;\n"
"  } else {\n"
"    return low * 2 + 1;\n"
"  }\n"
"}\n";