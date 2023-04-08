![Untitled design (1)](https://user-images.githubusercontent.com/96336775/185031271-af0c1ca2-4525-45a2-9639-cc9f56eb5ea2.png)


# Authify : The Authentication API
Secure, complete and hassle free authentication solution for your applications

**Website** :  https://api-authify.azurewebsites.net/

## Features

- Signup using Email and generation of unique JWT token.
- Signin
- Fetching User details from JWT token.
- Reseting Password via OTP on corresponding Email address.
- Authentication using Google.
- **Instant Updates on email for all account activity like login ,  change of password, and etc**

## Endpoints

### Signup

#### I Sending OTP to given email address:

```js
  POST https://api-authify.azurewebsites.net/auth/signup/email
```

#### Body :

| Parameter  | Type     | Description                             |
| :--------- | :------- | :-------------------------------------- |
| `email`    | `string` | **Required** Email Address                 |

#### Usage

javascript:

```javascript
const createNewUserViaEmail = await fetch('https://api-authify.herokuapp.auth/signup/email', {
    method: 'POST',
    headers: {
        'Content-Type': 'application/json'
    },
    body: JSON.stringify({ email: credentials.email})
});
const json = await createNewUserViaEmail.json();
console.log(json);
```

#### response

```javascript
{
  "success": true,
}

```

#### II Verivication and creation of a new user:

```js
  POST https://api-authify.azurewebsites.net/auth/signup/email/verify
```

#### Body :

| Parameter  | Type     | Description                             |
| :--------- | :------- | :-------------------------------------- |
| `name`     | `string` | **Required** Name (min length : 3)     |
| `email`    | `string` | **Required** Email add                 |
| `password` | `string` | **Required** password (min length : 8) |
| `authcode` | `number` | **Required** password (length : 6) |

#### Usage

javascript:

```javascript
const createNewUser = await fetch(
  "https://api-authify.azurewebsites.net/auth/signup",
  {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify({
      name: credentials.name,
      email: credentials.email,
      password: credentials.password,
      authcode: credentials.authCode
    }),
  }
);
const response = await createNewUser.json();
console.log(json);
```

#### response

```javascript
{
  "success": true,
  "authToken": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VyIjp7InVzZXIiOiI2MjljN2YzYWVmMzEwNjg4N2EyYWNkZDAifSwiaWF0IjoxNjU0NDIzMzU1fQ.R1rX4sRHv-o3gDWT3XqtobYEKeYRmyvA8ZLpveobuGc"
}

```

### Signin

```js
  POST https://api-authify.azurewebsites.net/auth/signin
```

#### Body :

| Parameter  | Type     | Description                             |
| :--------- | :------- | :-------------------------------------- |
| `email`    | `string` | **Required** Email address             |
| `password` | `string` | **Required** password (min length : 8) |

#### Usage

javascript:

```javascript
const signInUser = await fetch(
  "https://api-authify.azurewebsites.net/auth/signin",
  {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify({
      email: credentials.email,
      password: credentials.password,
    }),
  }
);
const response = await signInUser.json();
console.log(json);
```

#### response

```javascript
{
  "success": true,
  "authToken": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VyIjp7InVzZXIiOiI2MjljN2YzYWVmMzEwNjg4N2EyYWNkZDAifSwiaWF0IjoxNjU0NDIzMzU1fQ.R1rX4sRHv-o3gDWT3XqtobYEKeYRmyvA8ZLpveobuGc"
}

```

### Fetch User details from token \ Verification

```js
  POST https://api-authify.azurewebsites.net/auth/verifyuser
```

#### Header :

| Parameter      | Type     | Description                                                                                                                                                                       |
| :------------- | :------- | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `Content-Type` | `string` | **Required** application/json                                                                                                                                                    |
| `auth-token`   | `string` | **Required** eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1..... |

#### Usage

javascript:

```javascript
const getUser = await fetch(
  "https://api-authify.azurewebsites.net/auth/verifyuser",
  {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
      "auth-token":
        "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VyIjp7InVzZXIiOiI2MjljN2YzYWVmMzEwNjg4N2EyYWNkZDAifSwiaWF0IjoxNjU0NDIzMzU1fQ.R1rX4sRHv-o3gDWT3XqtobYEKeYRmyvA8ZLpveobuGc",
    },
  }
);
const response = await getUser.json();
console.log(json);
```

#### response

```javascript
{
  "_id": "629c7f3aef3106887a2acdd0",
  "name": "user",
  "email": "userEmail@fudnef.com",
  "googleId": null,
  "date": "2022-06-05T10:02:34.938Z",
  "__v": 0
}

```

### Reseting password
Can be used for both resetting the password and updation of password

#### I : Sending OTP to corresponding Email address

```js
  POST https://api-authify.azurewebsites.net/fogotpassword
```

#### Body :

| Parameter | Type     | Description                 |
| :-------- | :------- | :-------------------------- |
| `email`   | `string` | **Required**. Email address |

#### Usage

javascript:

```javascript
const sendMail = await fetch(
  "https://api-authify.azurewebsites.net/fogotpassword",
  {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify({ email: credentials.email }),
  }
);

const response = await sendMail.json();
console.log(response);
```

#### response

```javascript
{
  "success": true,
  "message": "Email Send"
}

```

### II : OTP verification and updating new password

```js
  POST https://api-authify.azurewebsites.net/fogotpassword/verify
```

#### Body :

| Parameter  | Type     | Description                                 |
| :--------- | :------- | :------------------------------------------ |
| `email`    | `string` | **Required**. Email address                 |
| `authcode` | `number` | **Required**. OTP (6 digit)                 |
| `password` | `string` | **Required**. new password (min length : 8) |

#### Usage

javascript:

```javascript
const changePassword = await fetch(
  "https://api-authify.azurewebsites.net/fogotpassword/verify",
  {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify({
      email: credentials.email,
      authcode: Number(credentials.OTP),
      password: credentials.password,
    }),
  }
);

const response = await changePassword.json();
```

#### response

```javascript
{
    "success" : true ,
    "msg" : "Password Updated"
}

```

### Authentication with Google

In order to make google based authentications seemless and secure, we use unique endpoint for every user to fetch corresponting token once user have successfully loggedin on google's Oauth authentication screen

#### I Initilizeation and Redirection to google's Oauth authentication screen

So to initialize the process, a random hash generated by any algorithm is send to server by client which has to be save temporarily by the cient for further process

```js
  PUT https://api-authify.azurewebsites.net/auth/googlecontext/:URI
```

#### Usage

javascript:

```html
<!-- Redirection to Oauth screen and trigger initialization -->
<a href='https://api-authify.azurewebsites.net/auth/google' target='_blank' onClick={gAuthInit} >Continue with Google</Link>


```

Install with npm

```bash
npm i md5

```

```javascript
import md5

const gAuthInit = ()=>{

    const authCode = Math.floor(100000 + Math.random() * 90000000); //generate a random long integer
    const uri = md5(authCode);

    const preConnect = await fetch(`https://api-authify.azurewebsites.net/auth/googlecontext/:${uri}`, {
        method: 'PUT'
    })

    const preConnectResponse = await preConnect.json();
    console.log(preConnectResponse);
    if(preConnectResponse.success == true){
        googleAuth(uri)
    }

}

```

#### response

```javascript
{
  "success": true
}

```

#### II Fetching Token on successfull login

Fetching token from unique endpoint

```js
  GET https://api-authify.azurewebsites.net/auth/g/user/${uri}
```

#### Usage

javascript:

```javascript
const googleAuth = (uri)=>{

    let data = undefined;

    while (data === undefined || data === null) {
        const response = await fetch(`https://api-authify.azurewebsites.net/auth/g/user/${uri}`, {
            method: 'GET'
        })

    const response = await response.json()
    console.log(response)
}

```

#### response

```javascript
{
  "success": true,
  "authToken": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VyIjp7InVzZXIiOiI2MjljN2YzYWVmMzEwNjg4N2EyYWNkZsgggegieaWF0IjoxNjU0NDIzMzU1fQ.R1rX4sRHv-o3gDWT3XqtobYEKeYRmyvA8ZLpveobuGc"
}

```


### Delete Account

#### I Sending Otp to given email address:

```js
  POST https://api-authify.azurewebsites.net/auth/delete/email
```

#### Body :

| Parameter  | Type     | Description                             |
| :--------- | :------- | :-------------------------------------- |
| `email`    | `string` | **Required** Email address             |

#### Usage

javascript:

```javascript
const deleteGen = await fetch('https://api-authify.azurewebsites.net/auth/delete/email', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({ email: user.email })
    })

    const response = await deleteGen.json();
    console.log(response)
```

#### response

```javascript
{
  "success": true,
}

```


#### II OTP verification and account deletion:

```js
  POST https://api-authify.azurewebsites.net/auth/delete/email
```

#### Body :

| Parameter  | Type     | Description                             |
| :--------- | :------- | :-------------------------------------- |
| `email`    | `string` | **Required** Email address             |
| `authcode`    | `number` | **Required** OTP (6 digit)           |
| `password`    | `string` | **Required** Password (min-length : 8)            |

#### Usage

javascript:

```javascript
const response = await fetch('https://api-authify.azurewebsites.net/auth/delete/email/verify', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({ email: user.email, authcode: Number(credentials.   verifyToken), password: credentials.password })
  })

const response = await deleteGen.json();
console.log(response)
```

#### response

```javascript
{
  "success": true,
}

```

## Support

For any issue or query I'll love to hear at : developer.authify@gmail.com

**We love contributions ❤️** <br>Contribute to this api <a href="https://github.com/MR-DHRUV/Authify-The-Authentication-API" target="_blank" rel="noopener noreferrer">here</a>


## Contact Me <br>


<a href="https://www.linkedin.com/in/dhruv-gupta-55034a228/" target="_blank" rel="noopener noreferrer">
  <img src="https://cdn-icons-png.flaticon.com/512/1384/1384014.png" alt="" width="50px" height="50px">
</a>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<a href="https://github.com/MR-DHRUV" target="_blank" rel="noopener noreferrer">
  <img src="https://cdn-icons-png.flaticon.com/512/733/733609.png" alt="" width="50px" height="50px">
</a>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<a href="mailto://developer.authify@gmail.com" target="_blank" rel="noopener noreferrer">
  <img src="https://cdn-icons-png.flaticon.com/512/60/60543.png" alt="" width="50px" height="50px">
</a>

