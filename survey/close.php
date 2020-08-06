<!doctype html>
<html lang="fr">
  <head>
  </head>

  <body>
    <?php echo "<script type='text/javascript'>closeWin();</script>"; ?>
    <script language="javascript">

        function closeWin() {
            window.opener=null;
            window.open('','_self');
            window.close();
        }
    </script>
  </body>
</html>