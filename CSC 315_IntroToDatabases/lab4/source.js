//used nodejs
//installed mysql, inquirer, and readline to nodejs

let mysql = require("mysql");

// connect the user
let con = mysql.createConnection({
  host: "localhost",
  user: "user1",
  password: "password",
  database: "lab4",
});

const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
const inquirer = require("inquirer");
console.log("1. See all students"); //display results of select
console.log("2. Add a student"); //insert student
console.log("3. Exit program");
rl.question("Select an action: ", (userInput) => {
  if (userInput.trim() == 1) {
    con.connect(function (err) {
      if (err) throw err;
      con.query(
        "SELECT * FROM student;--",
        function (err, result, fields) {
          if (err) throw err;
          console.log(result);
        }
      );
      con.end();
    });
    rl.close();
  } else if (userInput.trim() == 2) {
    var questions = [
      {
        name: "firstname",
        message: "Type in the first name:",
      },
      {
        name: "lastname",
        message: "type in the last name",
      },
      {
        name: "grade",
        message: "type in the grade for that student",
      },
    ];

    inquirer.prompt(questions).then((answers) => {
      let pose = { FirstName: "", LastName: "", Grade: "" };
      console.log(
        `first: ${answers["firstname"]}, last: ${answers["lastname"]}, grade: ${answers["grade"]}`
      );
      pose["FirstName"] = answers["firstname"];
      pose["LastName"] = answers["lastname"];
      pose["Grade"] = answers["grade"];

      con.connect(function (err) {
        if (err) throw err;
        //the ? helps prevent sql injections
        let sql = "INSERT INTO student SET ?;--";
        con.query(sql, pose, (err, result, fields) => {
          if (err) throw err;
          console.log(result);
        });

        console.log("INSERT COMPLETED!");

        let sql1 = "SELECT * FROM student WHERE grade > 5;--";
        con.query(sql1, (err, result, fields) => {
          if (err) throw err;
          console.log("Students with a grade more than 5");
          console.log(result);
        });
        con.end();
      });
    });
  } else if (userInput.trim() == 3) {
    con.end();
    rl.close();
  }
});
