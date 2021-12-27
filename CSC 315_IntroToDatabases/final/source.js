const mysql = require("mysql");
const inquirer = require("inquirer");
const readline = require("readline");
const {
  SIGQUIT
} = require("constants");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

// connect user
const con = mysql.createConnection({
  host: "localhost",
  user: "api",
  password: "password",
  database: "CSC315Final2021",
});

let question1 = [{
  name: "uid",
  message: "Type in the userID: "
}, ];

//menu for user to choose
let menu = () => {
  console.log("1. get region the sub-genre comes from");
  console.log("2. get similar sub-genre based on user favorites");
  console.log("3. get similar genre of a users favorite band");
  console.log("4. get other user favorites");
  console.log("5. get similar bands in other locations");
  console.log("6. add a user");
  console.log("7. add or delete favorites");
  rl.question("Select an action: (Choose a number)", (userInput) => {
    if (userInput.trim() == 1) {
      getSubGenreRegion();
      rl.close();
    } else if (userInput.trim() == 2) {
      getSimilarSubGenre();
    } else if (userInput.trim() == 3) {
      getSimilarGenre();
    } else if (userInput.trim() == 4) {
      otherUserFavs();
    } else if (userInput.trim() == 5) {
      similarBandsInOtherLocations();
    } else if (userInput.trim() == 6) {
      addUsers();
    } else if (userInput.trim() == 7) {
      addOrDeleteFavorites();
    }
  });
};

menu();


//task 4
let getSubGenreRegion = () => {
  con.connect((err) => {
    let stmt = `SELECT bs.bname, bs.sgname, c.rname AS region FROM band_styles bs
                INNER JOIN band_origins bo ON bo.bname LIKE CONCAT('%',bs.bname,'%')
                INNER JOIN country c ON c.cname LIKE CONCAT('%',bo.cname,'%');`;
    if (err) throw err;
    con.query(stmt, (err, result) => {
      if (err) throw err;
      console.log(result);
    });
    con.end();
  });
};

// NOTE: the ? helps prevent sql injections
//task 5
let getSimilarSubGenre = () => {
  inquirer.prompt(question1).then(answers => {
    let userID = answers["uid"];
    console.log(
      `id: ${answers["uid"]}`
    );
    con.connect((err) => {
      let stmt1 = `SELECT * FROM band_styles bs WHERE bs.sgname IN (SELECT bs.sgname FROM favorites f 
                    INNER JOIN bands b ON b.bid = f.bid
                    INNER JOIN band_styles bs ON bs.bname LIKE CONCAT('%',b.bname,'%')
                    WHERE f.userID = ?) AND bs.bname NOT IN (SELECT bname FROM favorites f
                    INNER JOIN bands b ON b.bid = f.bid WHERE f.userid = ?);--`;
      con.query(stmt1, [userID, userID], (err, result, fields) => {
        if (err) throw err;
        console.log(result);
      });

      con.end();
    });
  })
};

// NOTE: the ? helps prevent sql injections
//task 6
let getSimilarGenre = () => {
  inquirer.prompt(question1).then(answers => {
    let userID = answers["uid"];
    console.log(
      `id: ${answers["uid"]}`
    );
    con.connect((err) => {
      let stmt2 = `SELECT * FROM band_styles bs
            INNER JOIN sub_genre sg ON sg.sgname = bs.sgname
            WHERE sg.gname IN (SELECT sg.gname FROM sub_genre sg WHERE sg.sgname IN (SELECT bs.sgname FROM favorites f 
            INNER JOIN bands b ON b.bid = f.bid
            INNER JOIN band_styles bs ON bs.bname LIKE CONCAT('%',b.bname,'%')
            WHERE f.userID = ?)) AND bs.bname NOT IN (SELECT bname FROM favorites f
            INNER JOIN bands b ON b.bid = f.bid WHERE f.userid = ?);--`;
      con.query(stmt2, [userID, userID], (err, result, fields) => {
        if (err) throw err;
        console.log(result);
      });
      con.end();
    });
  })

};

// NOTE: the ? helps prevent sql injections
//task 7
let otherUserFavs = () => {
  inquirer.prompt(question1).then(answers => {
    let userID = answers["uid"];
    console.log(
      `id: ${answers["uid"]}`
    );
    con.connect((err) => {
      let stmt3 = `SELECT * FROM favorites f 
                WHERE f.UserID IN (SELECT f.userID FROM favorites f
                WHERE f.bid IN (SELECT b.bid FROM bands b WHERE b.bname IN (SELECT b.bname FROM favorites f 
                INNER JOIN bands b ON b.bid=f.bid
                WHERE f.userID=?)) AND f.userID NOT LIKE ?);--`;
      con.query(stmt3, [userID, userID], (err, result, fields) => {
        if (err) throw err;
        console.log(result);
      });
    });
  })

};

// NOTE: the ? helps prevent sql injections
//task 8
let similarBandsInOtherLocations = () => {
  inquirer.prompt(question1).then(answers => {
    let userID = answers["uid"];
    console.log(
      `id: ${answers["uid"]}`
    );
    con.connect((err) => {
      let stmt4 = `SELECT * FROM band_styles bs
                INNER JOIN sub_genre sg ON sg.sgname = bs.sgname
                INNER JOIN band_origins bo ON bo.bname LIKE CONCAT('%', bs.bname, '%')
                WHERE sg.gname IN (SELECT sg.gname FROM sub_genre sg WHERE sg.sgname IN (SELECT bs.sgname FROM favorites f 
                INNER JOIN bands b ON b.bid = f.bid
                INNER JOIN band_styles bs ON bs.bname LIKE CONCAT('%',b.bname,'%')
                WHERE f.userID = ?)) AND bs.bname NOT IN (SELECT bname FROM favorites f
                INNER JOIN bands b ON b.bid = f.bid WHERE f.userid = ?)
                AND bo.cname NOT IN (SELECT u.country FROM user u WHERE u.userID = ?);--`;
      con.query(stmt4, [userID, userID, userID], (err, result, fields) => {
        if (err) throw err;
        console.log(result);
      });
    });
  })
};

//task 11 -- add users
let addUsers = () => {
  let userquestion = [{
      name: "username",
      message: "Type in your username"
    },
    {
      name: "country",
      message: "Type in your country"
    }
  ];
  inquirer.prompt(userquestion).then(answers => {
    let pose = {
      username: "",
      country: ""
    };
    console.log(`username: ${answers["username"]}    country: ${answers["country"]}`)
    pose["username"] = answers["username"];
    pose["country"] = answers["country"];

    con.connect(err => {
      if (err) throw err;
      let addstmt = `INSERT INTO user SET ?; --`
      con.query(addstmt, pose, (err, result, fields) => {
        if (err) throw err;
        console.log(result);
      })
    })
  })
}


let addOrDeleteFavorites = () => {
  console.log("1. Add a favorite");
  console.log("2. Delete a favorite");
  rl.question("Select an action: (Choose a number)", (userInput) => {
    if (userInput.trim() == 1) {
      addFavorties();
    } else if (userInput.trim() == 2) {
      deleteFavorites();
    }
  })
}

//task 11-- add favorites
let addFavorties = () => {
  let addFavsquestion = [{
      name: "username",
      message: "Type in your username:"
    },
    {
      name: "bid",
      message: "Type in the band ID: "
    }
  ]
  inquirer.prompt(addFavsquestion).then(answers => {
    //get user ID
    let UID = "";
    con.connect(err => {
      if (err) throw err;
      let stmt7 = `SELECT userID FROM user WHERE username = ?;--`
      con.query(stmt7, answers["username"], (err, result, fields) => {
        if (err) throw err;
        UID = result[0].userID;
        console.log(UID)


        //put into favs
        let user1Add1 = {
          userID: UID,
          bid: answers["bid"],
        };
        let addfavstmt = `INSERT into favorites SET ?;--`;
        con.query(addfavstmt, user1Add1, (err, result, fields) => {
          if (err) throw err;
          console.log(result)
        })
      })
    })
  })
}

//task 11--delete favorites
let deleteFavorites = () => {
  let deleteFavsquestion = [{
      name: "username",
      message: "Type in your username:"
    },
    {
      name: "bid",
      message: "Type in the band ID: "
    }
  ]

  inquirer.prompt(deleteFavsquestion).then(answers => {
    //get user ID
    let UID = "";
    con.connect(err => {
      if (err) throw err;
      let stmt7 = `SELECT userID FROM user WHERE username = ?;--`
      con.query(stmt7, answers["username"], (err, result, fields) => {
        if (err) throw err;
        UID = result[0].userID;
        console.log(UID)


        //delete from favs
        let user1Delete1 = [{
          userID: UID,
        }, {bid: answers["bid"]}];
        let deletefavstmt = `DELETE FROM favorites WHERE ? AND ?;--`;
        con.query(deletefavstmt, user1Delete1, (err, result, fields) => {
          if (err) throw err;
          console.log(result)
        })
      })
    })
  })
}