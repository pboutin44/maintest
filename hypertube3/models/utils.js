module.exports = {
	escapeHtml: function(text) {
		var map = {
		    '&': '&amp;',
		    '<': '&lt;',
		    '>': '&gt;',
		    '"': '&quot;',
		    "'": '&#039;'
		};
		if (text)
  			return text.replace(/[&<>"']/g, function(m) { return map[m]; });
  		return text;
	},
	getAge: function(birth_date) {
	    if (birth_date.split('-').length - 1 == 0)
	        return -1;

	    var Year = birth_date.split('-')[0]
	    var Month = birth_date.split('-')[1]
	    var Day = birth_date.split('-')[2]
	    var today = new Date();
	    var age = today.getFullYear() - Year;
	    var m = today.getMonth() - Month;

	    if (m < 0 || (m === 0 && today.getDate() < Day))
	        age--;
    return age;
	}
}