#!/usr/bin/env python3

import os
from sys import stdin

class Content:
	def __init__(self):
		self.header = {}
		self.body = b''
	def parse_header(self, header_data):
		header_lines = header_data.split(b'\r\n')
		for line in header_lines:
			if b':' in line:
				key, value = line.split(b':', 1)
				self.header[key.strip().decode('utf-8')] = value.strip().decode('utf-8')
			else:
				self.header[line.strip().decode('utf-8')] = None
	def set_body(self, body_data):
		self.body = body_data
	def __str__(self):
		return f"Headers: {self.header}\nBody: {self.body}"

def save_image(filename, image_data):
	try:
		with open(filename, 'wb') as f:
			f.write(image_data)
			f.close()
	except Exception as e:
		print(f"Erro ao salvar o arquivo: {e}")

def getBoundary(content_type):
	if "boundary=" not in content_type:
		return 
	boundary = f'--{content_type.split("boundary=")[1].strip()}'.encode('utf-8')
	return boundary

def split_multpart(content_type, body):
	boundary = getBoundary(content_type)
	parts = body.split(boundary)
	return parts

def parse_part(part):
	part = part.strip(b'\r\n')
	delimiter = b'\r\n\r\n'

	value = part.split(delimiter, 1)
	if len(value) < 2:
		return None
	return value

def parse_header(header):
	if header == None:
		return None
	delimiter = b'\r\n'
	value = header.split(delimiter, 1)

def parse_header(header):
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

def setElements(content_parts, parts):
	for part in parts:
		value = parse_part(part)
		if value != None:
			header, body = value
			content = Content()
			content.set_body(body)
			content.parse_header(header)
			content_parts.append(content);

def setValueCreateFile(content_parts):
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
                    save_image(path_translated+filename, content.body)

    return titulo, subtitulo, filename


def generate_html(titulo, subtitulo, image_path, htmlFile):
	return f"""
		<div class="gallery-item">
			<img src="{image_path}" alt="Foto">
			<h3>{titulo}</h3>
			<p>{subtitulo}</p>
			<button class="delete-button" onclick="deleteFiles('{image_path}', '{htmlFile}', this)">Excluir</button>
        </div>"""

if __name__ == "__main__":
	request_method = os.environ.get("REQUEST_METHOD")
	query_string = os.environ.get("QUERY_STRING")
	path_info = os.environ.get("PATH_INFO")
	path_translated = os.environ.get("PATH_TRANSLATED")
	server_name = os.environ.get("SERVER_NAME")
	content_length = os.environ.get("CONTENT_LENGTH", "0")
	content_length = int(content_length) if content_length.isdigit() else 0
	content_type = os.environ.get("CONTENT_TYPE", "")
	body =  stdin.buffer.read(content_length)

	parts = split_multpart(content_type, body)
	content_parts = []
	setElements(content_parts, parts)
	titulo, subtitulo, filename  = setValueCreateFile(content_parts)
	htmlFile = path_info + titulo + subtitulo + '.html';
	with open(path_translated+titulo+subtitulo + ".html", "w") as arquivo:
		arquivo.write(generate_html(titulo, subtitulo, path_info+filename, htmlFile))
		arquivo.close()
	print("204 No Content")
	exit(0);