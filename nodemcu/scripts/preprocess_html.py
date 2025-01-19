import os
Import('env')


def clear_file(file_path):
    # Open the file in 'w' mode to clear its contents
    with open(file_path, 'w') as file:
        return


def read_html_file(file_path):
    with open(file_path, 'r') as file:
        return file.read()


def write_html_to_header(content, file_path, variable_name):
    with open(file_path, 'a+') as file:
        file.write(f'const char {variable_name}[] PROGMEM = R"rawliteral(\n')
        file.write(content)
        file.write('\n)rawliteral";\n')


def generate_header_for_html_page(html_path, output_path, variable_name):
    print(f"Reading HTML file: {html_path}")
    html_content = read_html_file(html_path)
    # Debug: Write the output header file
    print(f"Generating header file: {output_path}")
    write_html_to_header(html_content, output_path, variable_name)


# Path to the input HTML file
html_path_1 = os.path.join(env['PROJECT_DIR'], 'data', 'index.html')
# Path to the output header file
output_path = os.path.join(env['PROJECT_DIR'], 'src', 'index_html.h')

clear_file(output_path)
generate_header_for_html_page(html_path_1, output_path, 'index_html')

html_path_2 = os.path.join(env['PROJECT_DIR'], 'data', 'success.html')
generate_header_for_html_page(html_path_2, output_path, 'success_html')



print(f"Header file successfully generated: {output_path}")
