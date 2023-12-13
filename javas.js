<script>
   document.querySelectorAll('a[href^="#"]').forEach(anchor => {
      anchor.addEventListener('click', function (e) {
         e.preventDefault();

         document.querySelector(this.getAttribute('href')).scrollIntoView({
            behavior: 'smooth'
         });
      });
   });
</script>

<script>
   let prevScrollpos = window.pageYOffset;
   window.onscroll = function() {
      let currentScrollPos = window.pageYOffset;
      if (prevScrollpos > currentScrollPos) {
         document.querySelector(".header").style.top = "0";
      } else {
         document.querySelector(".header").style.top = "-80px";
      }
      prevScrollpos = currentScrollPos;
   }
</script>

<script>
   document.querySelector('form').addEventListener('submit', function (e) {
      let isValid = true;
      // Add your validation logic here
      // Example: Check if the email is valid
      let email = document.querySelector('input[type="email"]').value;
      if (!validateEmail(email)) {
         isValid = false;
         alert('Please enter a valid email address.');
      }

      if (!isValid) {
         e.preventDefault();
      }
   });

   function validateEmail(email) {
      // Add your email validation logic here
      // Example: Using a simple regex for demonstration
      let regex = /\S+@\S+\.\S+/;
      return regex.test(email);
   }
</script>
