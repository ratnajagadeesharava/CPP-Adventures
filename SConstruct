import os
# Initialize the environment


source_files = ["Employee.cpp","Human.cpp","lambdas.cpp","main.cpp","pointers.cpp","threads.cpp","Vector.cpp","SmartPointers.cpp"]
build_dir = "bin"

os.makedirs(build_dir, exist_ok=True)

target = os.path.join(build_dir, "cpp_adventures.exe")
env  =  Environment(ENV=os.environ,variant_dir=build_dir,duplicate=0)
object_files = []
for source_file in source_files:
    object_file = env.Object(target = os.path.join(build_dir, os.path.basename(source_file).replace(".cpp", ".obj")), source=source_file, variant_dir=build_dir)
    object_files.append(object_file)


env.Program(target, object_files)