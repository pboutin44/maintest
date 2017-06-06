$('header').load('/generic/html/header.html',function() {
	(function($){
	$.fn.translate = function(options) {

		var that = this; //a reference to ourselves

		var settings = {
			css: "trn",
			lang: "en"/*,
			t: {
				"translate": {
					pt: "tradução",
					br: "tradução"
				}
			}*/
		};
		settings = $.extend(settings, options || {});
		if (settings.css.lastIndexOf(".", 0) !== 0)   //doesn't start with '.'
			settings.css = "." + settings.css;

		var t = settings.t;

		//public methods
		this.lang = function(l) {
			if (l) {
				settings.lang = l;
				this.translate(settings);  //translate everything
			}

			return settings.lang;
		};
		this.get = function(index) {
			var res = index;

			try {
				res = t[index][settings.lang];
			}
			catch (err) {
				//not found, return index
				return index;
			}

			if (res)
				return res;
			else
				return index;
		};
		this.g = this.get;
		//main
		this.find(settings.css).each(function(i) {
			var $this = $(this);

			var trn_key = $this.attr("data-trn-key");
			if (!trn_key) {
				trn_key = $this.html();
				$this.attr("data-trn-key", trn_key);   //store key for next time
			}

			$this.html(that.get(trn_key));
		});
		return this;
	};
	})(jQuery);

	var dict = {
	  "My profile": {
	    fr: "Mon profil",
			en: "My profile"
	  },
	  "Research": {
	    fr: "Recherche",
	    en: "Research"
	  },
		"All profiles": {
	    fr: "tous les profiles",
	    en: "All profiles"
	  },
		"Log in with Github": {
	    fr: "se connecter avec Github",
	    en: "Log in with Github"
	  },
		"Logout": {
	    fr: "se deconnecter",
	    en: "Logout"
	  },
		"Not a member ? You may register !": {
	    fr: "Tu n'es pas membre ? Enregistres toi !",
	    en: "Not a member ? You may register !"
	  },
		"My profile": {
	    fr: "Mon profil",
	    en: "My profile"
	  },
		"First name": {
	    fr: "Prénom",
	    en: "First name"
	  },
		"Last name": {
	    fr: "nom",
	    en: "Last name"
	  },
		"First name": {
	    fr: "Prénom",
	    en: "First name"
	  },
		"Date of Birth": {
	    fr: "Date de naissance",
	    en: "Date of Birth"
	  },
		"First name": {
	    fr: "Prénom",
	    en: "First name"
	  },
		"Gender": {
	    fr: "Genre",
	    en: "Gender"
	  },
		"Female": {
	    fr: "Femme",
	    en: "Female"
	  },
		"Male": {
	    fr: "Homme",
	    en: "Male"
	  },
		"About me": {
	    fr: "A propos de moi",
	    en: "About me"
	  },
		"Load profile picture": {
	    fr: "charger une photo de profil",
	    en: "Load profile picture"
	  },
		"Browse": {
	    fr: "Parcourir",
	    en: "Browse"
	  },
		"Profile picture": {
	    fr: "photo de profil",
	    en: "Profile picture"
	  },
		"Update": {
	    fr: "mettre à jour",
	    en: "Update"
	  }
	}

	$("#language-fr").click(function() {
		console.log("tata")
		var translator = $('body').translate({lang: "en", t: dict}); //use English
		translator.lang("fr");
		$("#language").attr('src',"/img/flag-fr.png");
		$("#language-frA").attr('class',"active");
		$("#language-enA").removeClass("active");
		$.ajax({
			url: '/home/language',
			type: 'POST',
			data: {language: "fr"},
			success: function(user) {
				console.log("language is set");
				console.log(user);
			}
		});

	});
	$("#language-en").click(function() {
		var translator = $('body').translate({lang: "fr", t: dict}); //use English
		translator.lang("en");
		$("#language").attr('src',"/img/flag-gb.png");
		$("#language-enA").attr('class',"active");
		$("#language-frA").removeClass("active");
		$.ajax({
			url: '/home/language',
			type: 'POST',
			data: {language: "en"},
			success: function(user) {
				console.log("language is set");
				console.log(user);

			}

		});
	});
	(function (){
		$.ajax({
			url: '/home/language',
			type: 'POST',
			success: function(user) {
			if(user == "fr")
			{
				(function() {
					var translator = $('body').translate({lang: "en", t: dict}); //use English
					translator.lang("fr");
					$("#language").attr('src',"/img/flag-fr.png");
					$("#language-frA").attr('class',"active");
					$("#language-enA").removeClass("active");
					$.ajax({
						url: '/home/language',
						type: 'POST',
						data: {language: "fr"},
						success: function(user) {
							console.log("language is set");
							console.log(user);
						}

					});

				})();

			}
			else if(user == "en")
			{
			(function() {
					console.log("tati")
					var translator = $('body').translate({lang: "fr", t: dict}); //use English
					translator.lang("en");
					$("#language").attr('src',"/img/flag-gb.png");
					$("#language-enA").attr('class',"active");
					$("#language-frA").removeClass("active");
					$.ajax({
						url: '/home/language',
						type: 'POST',
						data: {language: "en"},
						success: function(user) {
							console.log("language is set");
							console.log(user);

						}

					});
				})();
			}


			}

		});

	})();


});


function dlTorrent (media_id) {
  $.ajax({
    url: "/home",
    type: "POST",
    data: {
      videos: 'torrent',
      media_id: media_id
    },
    success: function(link) {
      window.location.assign(link);
    }
  });
}

$(document).ready(function(){
  $.ajax({
    url: "/home",
    type: "POST",
    data: {
      videos: 'popular'
    },
    success: function(videos) {
      var row = $("<div class=\"row row-eq-height movie_row\"></div>");
      var div;
      $.each(videos, function(index, value) {

        div = $("<div id=\"" + index + "\"class=\" movie_box col-lg-3 col-md-3 col-sm-3 col-xs-6\"></div>");
        div.append($("<p class=\"movie_title\">" + value.title + "</p>"));
        div.append($("<br/>"));
        div.append($("<img class=\"movie_img img-responsive\" src='" + value.image + "'/>"));
        div.append($("<br/>"));
        div.click(function() {
          dlTorrent(/[^/]*$/.exec(value.image)[0]);
        });
        row.append(div);

        if ((index + 1) % 3 == 0 && (index + 1) != 0) {
            $("body").append(row);
            row = $("<div class=\"row row-eq-height movie_row\"></div>");
        }
      })
    }
  });
});

var dict = {
  "My profile": {
    fr: "Mon profil",
		en: "My profile"
  },
  "Research": {
    fr: "Recherche",
    en: "Research"
  },
	"All profiles": {
    fr: "tous les profiles",
    en: "All profiles"
  },
	"Log in with Github": {
    fr: "se connecter avec Github",
    en: "Log in with Github"
  },
	"Not a member ? You may register !": {
    fr: "Tu n'es pas membre ? Enregistres toi !",
    en: "Not a member ? You may register !"
  }
}


$(document).ready(function() {
  $("#language-fr").click(function(e) {
  	console.log("tata")
  	var translator = $('body').translate({lang: "en", t: dict}); //use English
  	translator.lang("fr");
  	$("#language").attr('src',"/img/flag-fr.png");
  	$("#language-frA").attr('class',"active");
  	$("#language-enA").removeClass("active");

  });
  $("#language-en").click(function(e) {
  	console.log("tata")
  	var translator = $('body').translate({lang: "fr", t: dict}); //use English
  	translator.lang("en");
  	$("#language").attr('src',"/img/flag-gb.png");
  	$("#language-enA").attr('class',"active");
  	$("#language-frA").removeClass("active");

  });
});
