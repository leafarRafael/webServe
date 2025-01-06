#!/usr/bin/env python3

import os
from sys import stdin, stdout

def exit_with_error():
    stdin.close()
    stdout.close()
    exit(1)

class Content:
    def __init__(self):
        self.header = {}
        self.body = b''

    def parse_header(self, header_data):
        try:
            header_lines = header_data.split(b'\r\n')
            for line in header_lines:
                if b':' in line:
                    key, value = line.split(b':', 1)
                    self.header[key.strip().decode('utf-8')] = value.strip().decode('utf-8')
                else:
                    self.header[line.strip().decode('utf-8')] = None
        except:
            exit_with_error()

    def set_body(self, body_data):
        self.body = body_data

    def __str__(self):
        return f"Headers: {self.header}\nBody: {self.body}"

def save_image(filename, image_data):
    try:
        with open(filename, 'wb') as f:
            f.write(image_data)
    except:
        exit_with_error()

def get_boundary(content_type):
    if not content_type or "boundary=" not in content_type:
        exit_with_error()
    try:
        boundary = f'--{content_type.split("boundary=")[1].strip()}'.encode('utf-8')
        return boundary
    except:
        exit_with_error()

def split_multipart(content_type, body):
    try:
        boundary = get_boundary(content_type)
        if not boundary:
            exit_with_error()
        parts = body.split(boundary)
        return parts
    except:
        exit_with_error()

def parse_part(part):
    try:
        part = part.strip(b'\r\n')
        delimiter = b'\r\n\r\n'
        value = part.split(delimiter, 1)
        if len(value) < 2:
            return None
        return value
    except:
        exit_with_error()

def parse_header(header):
    try:
        header = header.strip()
        parts = header.split(b';')
        header_dict = {}
        for part in parts:
            part = part.strip()
            if b'=' in part:
                key, value = part.split(b'=', 1)
                key = key.strip().decode('utf-8')
                value = value.strip().decode('utf-8')
                header_dict[key] = value
            else:
                header_dict[part.strip().decode('utf-8')] = None
        return header_dict
    except:
        exit_with_error()

def set_elements(content_parts, parts):
    try:
        for part in parts:
            value = parse_part(part)
            if value:
                header, body = value
                content = Content()
                content.set_body(body)
                content.parse_header(header)
                content_parts.append(content)
    except:
        exit_with_error()

def set_value_create_file(content_parts, path_translated):
    try:
        titulo = ""
        subtitulo = ""
        filename = ""

        for content in content_parts:
            content_disposition = content.header.get("Content-Disposition", "")
            if 'name=' in content_disposition:
                field_name = content_disposition.split('name="')[1].split('"')[0]    
                if field_name == "titulo":
                    titulo = content.body.decode("utf-8")        
                elif field_name == "subtitulo":
                    subtitulo = content.body.decode("utf-8")    
                elif field_name == "foto":
                    filename = None
                    if 'filename=' in content_disposition:
                        filename = content_disposition.split('filename="')[1].split('"')[0]
                    if filename:
                        save_image(path_translated + filename, content.body)

        return titulo, subtitulo, filename
    except:
        exit_with_error()

def generate_html(titulo, subtitulo, image_path, html_file):
    try:
        return f"""
        <div class="gallery-item">
            <img src="{image_path}" alt="Foto">
            <h3>{titulo}</h3>
            <p>{subtitulo}</p>
            <button class="delete-button" onclick="deleteFiles('{image_path}', '{html_file}', this)">Excluir</button>
        </div>"""
    except:
        exit_with_error()


if __name__ == "__main__":
	try:
		request_method = os.environ.get("REQUEST_METHOD", "")
		query_string = os.environ.get("QUERY_STRING", "")
		path_info = os.environ.get("PATH_INFO", "")
		path_translated = os.environ.get("PATH_TRANSLATED", "")
		server_name = os.environ.get("SERVER_NAME", "")
		content_length = os.environ.get("CONTENT_LENGTH", "0")
		content_length = int(content_length) if content_length.isdigit() else 0
		content_type = os.environ.get("CONTENT_TYPE", "")

		body = stdin.buffer.read(content_length)
		parts = split_multipart(content_type, body)
		content_parts = []
		set_elements(content_parts, parts)
		titulo, subtitulo, filename = set_value_create_file(content_parts, path_translated)

		html_file = path_info + titulo + subtitulo + '.html'
		with open(path_translated + titulo + subtitulo + ".html", "w") as arquivo:
			arquivo.write(generate_html(titulo, subtitulo, path_info + filename, html_file))
	except:
		stdin.close()
		stdout.close()
		exit_with_error()
	stdin.close()
	stdout.close()
	exit(0)