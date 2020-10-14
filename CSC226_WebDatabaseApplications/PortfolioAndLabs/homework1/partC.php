<!DOCTYPE html>
<html> 
  <head>  
      <title>Number Array</title>
      <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
      <link rel="stylesheet" href="../style.css">
  </head>
<body style="background-color: #F4F9E9;">
<p>
  <a style="font-size: 50px;" href="partB.html" title="go back?">&#8592;</a>
</p>
<table class="table table-sm">
    <thead>
      <tr>
        <th scope="col">Numbers</th>
        <th scope="col">Results</th>
      </tr>
    </thead>
    <tbody>
  <?php
  for($i = 0; $i<=100; $i++){
      echo "<tr>";
      if($i % 2 == 0){
          echo "<td> $i </td>";
          echo "<td>even</td>";
      }
      else{
          echo "<td> $i </td>";
          echo "<td>odd</td>";
      }
      echo "</tr>";
  }
  ?>
</tbody>
</table>

  <script src="https://code.jquery.com/jquery-3.4.1.slim.min.js" integrity="sha384-J6qa4849blE2+poT4WnyKhv5vZF5SrPo0iEjwBvKU7imGFAV0wwj1yYfoRSJoZ+n" crossorigin="anonymous"></script>
  <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.0/dist/umd/popper.min.js" integrity="sha384-Q6E9RHvbIyZFJoft+2mJbHaEWldlvI9IOYy5n3zV9zzTtmI3UksdQRVvoxMfooAo" crossorigin="anonymous"></script>
  <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/js/bootstrap.min.js" integrity="sha384-wfSDF2E50Y2D1uUdj0O3uMBJnjuUD4Ih7YwaYd1iqfktj0Uod8GCExl3Og8ifwB6" crossorigin="anonymous"></script>
</body>
</html>