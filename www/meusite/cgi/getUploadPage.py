#!/usr/bin/env python3

import os

html_open = '''<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Galeria de Imagens</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            background-color: #f4f4f4;
        }

        .gallery {
            display: grid;
            grid-template-columns: repeat(4, 1fr);
            gap: 20px;
            padding: 20px;
        }

        .gallery-item {
            text-align: center;
            border: 1px solid #ccc;
            border-radius: 5px;
            padding: 10px;
            background-color: #fff;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
        }

        .gallery-item img {
            max-width: 100%;
            height: auto;
            border-radius: 5px;
        }

        .gallery-item h3 {
            margin: 10px 0 5px;
            font-size: 18px;
        }

        .gallery-item p {
            margin: 0;
            font-size: 16px;
            color: #555;
        }

        @media (max-width: 1200px) {
            .gallery {
                grid-template-columns: repeat(3, 1fr);
            }
        }

        @media (max-width: 800px) {
            .gallery {
                grid-template-columns: repeat(2, 1fr);
            }
        }

        @media (max-width: 500px) {
            .gallery {
                grid-template-columns: 1fr;
            }
        }
    </style>
	</head>
	<body>
		<h1 style="text-align: center; margin-top: 20px;">Galeria de Imagens</h1>
		<div class="gallery">'''

html_close = '''
	</div>
</body>
</html>'''

if __name__ == "__main__":
    request_method = os.environ.get("REQUEST_METHOD")
    query_string = os.environ.get("QUERY_STRING")
    path_info = os.environ.get("PATH_INFO")
    path_translated = os.environ.get("PATH_TRANSLATED")
    server_name = os.environ.get("SERVER_NAME")
    content_length = os.environ.get("CONTENT_LENGTH", "0")
    content_length = int(content_length) if content_length.isdigit() else 0
    content_type = os.environ.get("CONTENT_TYPE", "")

    print(html_open)
    for file_name in os.listdir(path_translated):
        complet_path = os.path.join(path_translated, file_name)
        if os.path.isfile(complet_path) and file_name.endswith(".data"):
            with open(complet_path, 'r') as arquivo:
                content = arquivo.read()
                print(content)
    print(html_close)
