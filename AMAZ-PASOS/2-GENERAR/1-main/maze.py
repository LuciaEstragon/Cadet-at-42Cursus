# ejercicio Py2 -ex02, ex03 y ex04

import sys

from config_params import ConfigParams

class Maze (ConfigParams):
    def get_input_file(self):
        try:
            f_out = open(self.out_file, 'w')
            f_out.writelines("Hola")
            f_out.close()
        except PermissionError as e:
            print("[STDERR] Error opening file "
                  f"'{new_filename}': {e}", file=sys.stderr)
            print("Data not saved.")
        except Exception as e:
            print(f"[STDERR] Unexpected error: {e}", file=sys.stderr)