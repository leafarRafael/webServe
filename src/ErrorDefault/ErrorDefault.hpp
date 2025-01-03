/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorDefault.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:25:12 by rbutzke           #+#    #+#             */
/*   Updated: 2025/01/03 14:47:13 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <map>

class ErrorDefault{
	private:
		static std::map<int, std::string> _error;
		
		ErrorDefault(){};
		~ErrorDefault(){};
        static void initError();
	public:
		static std::string	getHTML(int errorCode);
};

#define HTML_ERROR_CLOSE "\
	 <a href=\"/\">Return to homepage</a>\n\
    </div>\n\
</body>\n\
</html>\n"

#define HTML_ERROR_OPEN "\
<!DOCTYPE html>\n\
<html lang=\"en\">\n\
<head>\n\
    <meta charset=\"UTF-8\">\n\
    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n\
    <title>404 Not Found</title>\n\
    <style>\n\
        body {\n\
            font-family: Arial, sans-serif;\n\
            text-align: center;\n\
            background-color: #f2f2f2;\n\
            color: #333;\n\
            margin: 0;\n\
            padding: 0;\n\
            display: flex;\n\
            justify-content: center;\n\
            align-items: center;\n\
            height: 100vh;\n\
        }\n\
        .container {\n\
            max-width: 600px;\n\
            padding: 20px;\n\
            background-color: #fff;\n\
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);\n\
            border-radius: 8px;\n\
        }\n\
        h1 {\n\
            font-size: 3em;\n\
            color: #e74c3c;\n\
            margin: 0;\n\
        }\n\
        p {\n\
            font-size: 1.2em;\n\
            margin: 15px 0;\n\
        }\n\
        a {\n\
            color: #3498db;\n\
            text-decoration: none;\n\
            font-weight: bold;\n\
        }\n\
        a:hover {\n\
            text-decoration: underline;\n\
        }\n\
    </style>\n\
</head>\n\
<body>\n\
    <div class=\"container\">\n"
