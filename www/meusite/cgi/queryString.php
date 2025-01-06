#!/usr/bin/php
<?php
function escape_html($value) {
    return htmlspecialchars($value, ENT_QUOTES, 'UTF-8');
}


$query_string = isset($_SERVER['QUERY_STRING']) ? $_SERVER['QUERY_STRING'] : '';

echo "<!DOCTYPE html>";
echo "<html lang='en'>";
echo "<head>";
echo "<meta charset='UTF-8'>";
echo "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
echo "<title>CGI Variables - Formatted</title>";
echo "<style>";
echo "body { font-family: Arial, sans-serif; background-color: #f4f4f4; color: #333; padding: 20px; margin: 0; }";
echo "h1 { text-align: center; color: #4CAF50; }";
echo "ul { list-style-type: none; padding: 0; margin: 20px auto; width: 90%; max-width: 600px; background: #fff; border: 1px solid #ddd; border-radius: 8px; padding: 20px; box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1); }";
echo "li { font-size: 18px; padding: 8px 0; }";
echo "strong { color: #333; }";
echo ".container { display: flex; flex-direction: column; align-items: center; }";
echo ".btn { background-color: #4CAF50; color: white; padding: 10px 20px; border: none; border-radius: 5px; cursor: pointer; margin: 10px 0; text-align: center; }";
echo ".btn:hover { background-color: #45a049; }";
echo ".back-btn { background-color: #f44336; }";
echo ".back-btn:hover { background-color: #e53935; }";
echo "</style>";
echo "</head>";
echo "<body>";
echo "<div class='container'>";
echo "<h1>CGI Query String Data</h1>";


echo "<ul>";
echo "<li><strong>QUERY_STRING:</strong> " . escape_html($query_string) . "</li>";
echo "</ul>";


if (!empty($query_string)) {
    parse_str($query_string, $params);

    $first_name = $params['first_name'] ?? '';
    $last_name = $params['last_name'] ?? '';
    $phone = $params['phone'] ?? '';

    echo "<ul>";
    echo "<li><strong>Nome:</strong> " . escape_html($first_name) . "</li>";
    echo "<li><strong>Sobrenome:</strong> " . escape_html($last_name) . "</li>";
    echo "<li><strong>Telefone:</strong> " . escape_html($phone) . "</li>";
    echo "</ul>";


    echo "<button class='btn back-btn' onclick='window.location.href=\"/\"'>Voltar para Página Principal</button>";
	echo "<button class='btn back-btn' onclick='window.location.href=\"/form/formQueryString.html\"'>Voltar para Página QueryString</button>";
} else {
    echo "<p style='text-align: center;'>Nenhum dado foi recebido na query string.</p>";
    echo "<button class='btn back-btn' onclick='window.location.href=\"/\"'>Voltar para Página Principal</button>";
}

echo "</div>";
echo "</body>";
echo "</html>";
?>
