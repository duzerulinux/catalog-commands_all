var data;
var modificacao = new Date(document.lastModified);
var dia  = modificacao.getDate();
var dia2 = (dia < 10) ? '0' + dia : dia;
var mes  = modificacao.getMonth() + 1;
var mes2 = (mes < 10) ? '0' + mes : mes;
var ano  = modificacao.getFullYear();
if (navigator.appname =='Netscape')
  {
    ano+=1900;
  }
data = dia2+'/'+mes2+'/'+ano;
document.write('Atualizado em '+data);

