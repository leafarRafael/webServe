function validateForm() {
	var titulo = document.forms["uploadForm"]["titulo"].value;
	var subtitulo = document.forms["uploadForm"]["subtitulo"].value;
	var foto = document.forms["uploadForm"]["foto"].value;

	if (titulo == "" || subtitulo == "" || foto == "") {
		alert("Por favor, preencha todos os campos obrigatórios.");
		return false;
	}
	return true;
}