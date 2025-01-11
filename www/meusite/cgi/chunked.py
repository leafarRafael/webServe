#!/usr/bin/env python3

import os
import sys

def main():
    content_length = os.environ.get("CONTENT_LENGTH", "0")
    content_length = int(content_length) if content_length.isdigit() else 0
    request_body = sys.stdin.read(content_length)
    print("Content-Type: text/html")
    print()
    print(f"""<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>CGI Response chunked type</title>
</head>
<body>
  <h1>Received Data</h1>
  <pre>{request_body}</pre>
</body>
</html>
""")

if __name__ == "__main__":
    main()