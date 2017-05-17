$.ajax({
  url : '/search/all_profil',
  type : 'GET',
  // dataType : 'html',
  success : function(code_html, statut){
    console.log("toktok");
  
//     let p1 = new Promise(
//             // The resolver function is called with the ability to resolve or
//             // reject the promise
//         //    console.log("quotas");
//            (resolve, reject) => {
//              console.log("quotas");
//              console.log(code_html[0].pacinput);
//              code_html.sort(function (a, b) {
//                if(code_html[0].pacinput)
//                {
//                  if(a.CurrentPosition && b.CurrentPosition)
//                  {
//                    $.ajax({
//                      url : 'https://maps.googleapis.com/maps/api/distancematrix/json?origins='+a.CurrentPosition+'&destinations='+code_html[0].pacinput+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg',
//                      type : 'GET',
//                      // dataType : 'html',
//                      success : function(code_html1, statut){
//                        console.log(code_html1.rows[0].distance.value);
//                        $.ajax({
//                          url : 'https://maps.googleapis.com/maps/api/distancematrix/json?origins='+b.CurrentPosition+'&destinations='+code_html[0].pacinput+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg',
//                          type : 'GET',
//                          // dataType : 'html',
//                          success : function(code_html2, statut){
//                            console.log("tavhe");
//                            console.log(code_html2.rows[0].distance.value);
//                            if(code_html1.rows[0].distance.value < code_html2.rows[0].distance.value)
//                              return 1;
//                            else {
//                              return -1
//                            }
//                          }
//                        })
//                      }
//                    })
//                  }
//
//                else if (a.CurrentPosition && !b.CurrentPosition)
//                {
//                 console.log("chaman1");
//                 console.log(a.CurrentPosition);
//                }
//                else if (!a.CurrentPosition && b.CurrentPosition) {
// console.log("chaman2");
//                }
//                else if (!a.CurrentPosition && !b.CurrentPosition) {
// console.log("chaman3");
//                }
//              }
//                console.log("chaman");
//              })
//
//             }
//         );
    //
    //   p1.then(function(val) {console.log(code_html);
    //   console.log("camenber");
    // });
    // p1.catch(
    //     // Log the rejection reason
    //    (reason) => {
    //         console.log('Handle rejected promise ('+reason+') here.');
    //     });


  console.log(code_html);
  console.log(code_html.mine);
  for(var i= 0; i < code_html.length - 1; i++)
  {

    //  console.log(ImageExist("/"+code_html[i].email+"/photo1.png"));
    // if(ImageExist("/"+code_html[i].email+"/photo1.png") == true)
    // {
    console.log(code_html);
    console.log(code_html[i].email);
    console.log('DETER');
    console.log(code_html[code_html.length - 1]);
    console.log('DETER2');
    console.log(code_html[i].email);
    console.log(code_html[code_html.length - 1]);
    if(code_html[i].email != code_html[code_html.length - 1].mine)
    {
      $('#main').append('<div class="col-lg-3 col-md-6"><div class="widget widget-shadow"><div class="widget-header bg-green-600 padding-30 white"><a class="avatar avatar-100" onclick="mini_profil(`'+code_html[i].email+'`);" img-bordered bg-white pull-left margin-right-20" href="javascript:void(0)"><img src= "/'+code_html[i].email+'/photo1.png" alt=""></a><div class="vertical-align height-100 text-truncate"><div class="vertical-align-middle"><div class="font-size-20 margin-bottom-5 text-truncate">'+code_html[i].firstname+' '+code_html[i].surname+'</div><button type="button" id="id" onclick="like(`'+code_html[i].email+'`);" class="btn btn-outline">Like</button>  <button type="button" id="id" onclick="Chat(`'+code_html[i].email+'`);" class="btn btn-outline">Chat</button></div></div></div></div></div>');
    }
  }
},
error : function(resultat, statut, erreur){
  console.log("pierromoutarde");
},
});
